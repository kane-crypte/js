import React from "react";

const Footer = () => {
  return (
    <footer className="bg-gray-900 text-white p-6 text-center">
      <p>&copy; {new Date().getFullYear()} Ton Nom. Tous droits réservés.</p>
      <div className="mt-4">
        <a href="https://www.linkedin.com" target="_blank" rel="noopener noreferrer" className="mx-3 text-blue-500 hover:text-blue-700">
          LinkedIn
        </a>
        <a href="https://github.com" target="_blank" rel="noopener noreferrer" className="mx-3 text-blue-500 hover:text-blue-700">
          GitHub
        </a>
        <a href="https://twitter.com" target="_blank" rel="noopener noreferrer" className="mx-3 text-blue-500 hover:text-blue-700">
          Twitter
        </a>
      </div>
    </footer>
  );
};

export default Footer;
