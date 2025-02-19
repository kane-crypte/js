import React, { useState } from "react";

const Contact = () => {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [message, setMessage] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();
    alert(`Message envoyé par ${name}`);
  };

  return (
    <section id="contact" className="p-10 bg-gray-100">
      <h2 className="text-3xl font-bold text-center mb-6">Contact</h2>
      <form onSubmit={handleSubmit} className="max-w-md mx-auto space-y-4">
        <input className="w-full p-2 border rounded" type="text" placeholder="Nom" value={name} onChange={(e) => setName(e.target.value)} />
        <input className="w-full p-2 border rounded" type="email" placeholder="Email" value={email} onChange={(e) => setEmail(e.target.value)} />
        <textarea className="w-full p-2 border rounded" rows="4" placeholder="Message" value={message} onChange={(e) => setMessage(e.target.value)} />
        <button className="w-full bg-blue-500 text-white p-2 rounded" type="submit">Envoyer</button>
      </form>
    </section>
  );
};

export default Contact;
