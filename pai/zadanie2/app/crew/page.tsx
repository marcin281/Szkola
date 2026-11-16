"use client";

import { useState, useEffect } from "react";
import Link from "next/link";

export default function Crew() {
  const [crew, setCrew] = useState<any[]>([]);
  const [team, setTeam] = useState<any[]>([]);

  useEffect(() => {
    setCrew(JSON.parse(localStorage.getItem("crew") || "[]"));
    setTeam(JSON.parse(localStorage.getItem("team") || "[]"));
  }, []);

  return (
    <div>
      <h2>CREW</h2>

      <Link href="/crew/add">Add crew member</Link>

      {crew.map((member, i) => (
        <div className="crew-member" key={i}>
          <p>{member.name}</p>
        </div>
      ))}


      

      <h1>TEAM 1</h1>
      <Link href="/crew/team?team=team1">Dodaj do teamu</Link>
<ol>
  {team
    .filter((member) => member.team === "team1")
    .map((member, i) => (
      <li key={i}>{member.name}</li>
    ))}
</ol>

<h1>TEAM 1</h1>
<Link href="/crew/team?team=team2">Dodaj do teamu</Link>

<ol>
  {team
    .filter((member) => member.team === "team2")
    .map((member, i) => (
      <li key={i}>{member.name}</li>
    ))}
</ol>
    </div>
  );
}