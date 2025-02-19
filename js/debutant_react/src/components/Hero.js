import React from "react";

const Hero = () => {
  return (
    <section className="h-screen flex flex-col justify-center items-center bg-gray-800 text-white text-center">
      <h2 className="text-4xl font-bold">Bonjour, je suis [Ton Nom]</h2>
      <p className="mt-2 text-lg">Développeur Web | React | C++ | Sécurité</p>
      <a href="#projects" className="mt-4 px-6 py-2 bg-blue-500 rounded">
        Voir mes projets
      </a>
    </section>
  );
};

export default Hero;
