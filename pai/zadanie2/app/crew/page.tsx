"use client";

import { useState, useEffect } from "react";
import Link from "next/link";

export default function Crew() {
  const [crew, setCrew] = useState<any[]>([]);

  useEffect(() => {
    setCrew(JSON.parse(localStorage.getItem("crew") || "[]"));
  }, []);

  return (
    <div>
      <h2>CREW</h2>

      <Link href="/crew/add">Add crew member</Link>

      {crew.map((member, i) => (
  <div className="crew-member" key={i}>
    <p>{member.name} {member.surname}</p>
    <p>{member.role}</p>
  </div>
))}
    </div>
  );
}