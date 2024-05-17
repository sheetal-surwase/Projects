// JavaScript code for the coffee shop website

// Function to toggle the mobile menu
function toggleMenu() {
  var menu = document.getElementById("nav-menu");
  menu.classList.toggle("active");
}

// Function to handle form submission
function submitForm(event) {
  event.preventDefault();

  // Get form values
  var name = document.getElementById("name").value;
  var email = document.getElementById("email").value;
  var message = document.getElementById("message").value;

  // Validate form data
  if (name.trim() === "" || email.trim() === "" || message.trim() === "") {
    alert("Please fill in all fields.");
    return;
  }

  // Display success message
  alert("Form submitted successfully!");

  // Clear form fields
  document.getElementById("name").value = "";
  document.getElementById("email").value = "";
  document.getElementById("message").value = "";
}

// Add event listeners after the page has loaded
document.addEventListener("DOMContentLoaded", function () {
  // Add click event listener to the mobile menu button
  var menuButton = document.getElementById("menu-button");
  menuButton.addEventListener("click", toggleMenu);

  // Add submit event listener to the contact form
  var contactForm = document.getElementById("contact-form");
  contactForm.addEventListener("submit", submitForm);
});
