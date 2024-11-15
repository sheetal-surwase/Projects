from PIL import Image, ImageChops, ImageEnhance, ImageDraw

def ela_analysis(image_path, quality=90):
    try:
        # Load the original image
        original_image = Image.open(image_path)
        original_image.save("temp.jpg", "JPEG", quality=quality)
        temp_image = Image.open("temp.jpg")

        # Adjust brightness and contrast for clarity
        original_image = ImageEnhance.Brightness(original_image).enhance(1.5)
        original_image = ImageEnhance.Contrast(original_image).enhance(1.5)

        # Compute the Error Level Analysis (ELA) image
        ela_image = ImageChops.difference(temp_image, original_image)
        extrema = ela_image.getextrema()
        max_diff = max([ex[1] for ex in extrema])
        scale = 255.0 / max_diff if max_diff != 0 else 1

        # Enhance the ELA image brightness for visibility
        ela_image = ImageEnhance.Brightness(ela_image).enhance(scale)
        return ela_image
    except Exception as e:
        print("Error performing ELA analysis:", str(e))
        return None

def forgery_detection(image_path, output_ela_path, output_marked_path, block_size=16, threshold=30):
    ela_image = ela_analysis(image_path)

    if ela_image is not None:
        # Save the ELA image
        ela_image.save(output_ela_path)
        print(f"ELA image saved at: {output_ela_path}")

        # Create a copy of the ELA image for marking suspicious blocks
        marked_image = ela_image.convert("RGB")
        draw = ImageDraw.Draw(marked_image)

        width, height = ela_image.size
        detected = False

        # Analyze blocks for potential forgery
        for x in range(0, width, block_size):
            for y in range(0, height, block_size):
                block = ela_image.crop((x, y, x + block_size, y + block_size))
                extrema = block.getextrema()
                max_diff = max([ex[1] for ex in extrema])

                # Mark the block if it exceeds the threshold
                if max_diff > threshold:
                    detected = True
                    draw.rectangle([(x, y), (x + block_size, y + block_size)], outline="red", width=2)

        if detected:
            marked_image.save(output_marked_path)
            print(f"Suspicious areas marked and saved at: {output_marked_path}")
        else:
            print("No significant forgeries detected.")

if __name__ == "__main__":
    # User inputs
    image_path = input("Enter the path of the image to analyze: ")
    output_ela_path = "ela_output.jpg"
    output_marked_path = "marked_output.jpg"
    quality = int(input("Enter JPEG quality for ELA analysis (default is 90): ") or "90")
    block_size = int(input("Enter block size for forgery analysis (default is 16): ") or "16")
    threshold = int(input("Enter detection threshold (default is 30): ") or "30")

    # Run the forgery detection
    forgery_detection(image_path, output_ela_path, output_marked_path, block_size, threshold)
