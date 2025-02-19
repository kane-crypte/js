import React from "react";

const projects = [
  { title: "Projet 1", description: "Description du projet 1", link: "#" },
  { title: "Projet 2", description: "Description du projet 2", link: "#" },
  { title: "Projet 3", description: "Description du projet 3", link: "#" },
];

const Projects = () => {
  return (
    <section id="projects" className="p-10 bg-gray-100">
      <h2 className="text-3xl font-bold text-center mb-6">Mes Projets</h2>
      <div className="grid md:grid-cols-3 gap-6">
        {projects.map((project, index) => (
          <div key={index} className="bg-white p-4 shadow-lg rounded-lg">
            <h3 className="text-xl font-bold">{project.title}</h3>
            <p>{project.description}</p>
            <a href={project.link} className="text-blue-500">Voir plus</a>
          </div>
        ))}
      </div>
    </section>
  );
};

export default Projects;
