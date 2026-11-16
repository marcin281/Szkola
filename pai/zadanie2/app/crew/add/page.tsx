"use client";

import { useState } from "react";
import { useRouter } from "next/navigation";

export default function AddCrew() {
  const [name, setName] = useState("");

  const router = useRouter();

  const addCrew = () => {
    const crew = JSON.parse(localStorage.getItem("crew") || "[]");

    crew.push({ name});

    localStorage.setItem("crew", JSON.stringify(crew));

    router.push("/crew");
  };

  return (
    <div>
      <h2>Add crew member</h2>

      <form className="crew-form" onSubmit={(e) => {
        e.preventDefault();
        addCrew();
        }}>
            <input placeholder="Name" onChange={e => setName(e.target.value)} />
            <button type="submit">Add crew member</button>
        </form>
    </div>
  );
}