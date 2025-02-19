import React from "react";

const skills = ["React", "JavaScript", "C++", "SQL", "Sécurité", "Python"];

const Skills = () => {
  return (
    <section id="skills" className="p-10 bg-gray-200">
      <h2 className="text-3xl font-bold text-center mb-6">Compétences</h2>
      <div className="flex flex-wrap justify-center gap-3">
        {skills.map((skill, index) => (
          <span key={index} className="bg-blue-500 text-white px-4 py-2 rounded">
            {skill}
          </span>
        ))}
      </div>
    </section>
  );
};

export default Skills;
