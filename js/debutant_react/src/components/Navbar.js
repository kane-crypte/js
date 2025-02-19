import React, { useState } from "react";

const Navbar = () => {
  const [menuOpen, setMenuOpen] = useState(false);

  return (
    <nav className="bg-gray-900 text-white p-4 flex justify-between items-center">
      <h1 className="text-2xl font-bold">Mon Portfolio</h1>
      <button onClick={() => setMenuOpen(!menuOpen)} className="md:hidden">
        ☰
      </button>
      <ul className={`md:flex ${menuOpen ? "block" : "hidden"} space-x-4`}>
        <li><a href="#projects">Projets</a></li>
        <li><a href="#skills">Compétences</a></li>
        <li><a href="#contact">Contact</a></li>
      </ul>
    </nav>
  );
};

export default Navbar;
