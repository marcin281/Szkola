"use client";

import { useState, useEffect } from "react";

export default function Crew() {
  const [crew, setCrew] = useState<any[]>([]);
  const [name, setName] = useState("");
  const [surname, setSurname] = useState("");
  const [role, setRole] = useState("");

  useEffect(() => {
    setCrew(JSON.parse(localStorage.getItem("crew") || "[]"));
  }, []);

  const addCrew = () => {
    const updated = [...crew, { name, surname, role }];
    setCrew(updated);
    localStorage.setItem("crew", JSON.stringify(updated));
  };

  return (
    <div>
      <input placeholder="Name" onChange={e => setName(e.target.value)} />
      <input placeholder="Surname" onChange={e => setSurname(e.target.value)} />
      <input placeholder="Role" onChange={e => setRole(e.target.value)} />

      <button onClick={addCrew}>Add</button>

      {crew.map((member, i) => (
        <p key={i}>
          {member.name} {member.surname} - {member.role}
        </p>
      ))}
    </div>
  );
}