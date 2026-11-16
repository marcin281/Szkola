"use client";

import { useState, useEffect } from "react";
import { useRouter, useSearchParams } from "next/navigation";

export default function AddCrew() {
  const [name, setName] = useState("");
  const [team, setTeam] = useState("team1");
  const [crew, setCrew] = useState<any[]>([]);

  const router = useRouter();
  const searchParams = useSearchParams();

  useEffect(() => {
    setCrew(JSON.parse(localStorage.getItem("crew") || "[]"));

    const selectedTeam = searchParams.get("team");

    if (selectedTeam === "team1" || selectedTeam === "team2") {
      setTeam(selectedTeam);
    }
  }, [searchParams]);

  const addTeam = () => {
    if (!name) return;

    const teams = JSON.parse(localStorage.getItem("team") || "[]");

    const updatedTeams = teams.filter(
      (member: any) => member.name !== name
    );

    updatedTeams.push({
      name: name,
      team: team
    });

    localStorage.setItem("team", JSON.stringify(updatedTeams));

    router.push("/crew");
  };

  return (
    <div>
      <h2>Add team member</h2>

      <form
        className="team-form"
        onSubmit={(e) => {
          e.preventDefault();
          addTeam();
        }}
      >
        <select
          value={name}
          onChange={(e) => setName(e.target.value)}
          required
        >
          <option value="">Select crew member</option>

          {crew.map((member, i) => (
            <option key={i} value={member.name}>
              {member.name}
            </option>
          ))}
        </select>

        <select
          value={team}
          onChange={(e) => setTeam(e.target.value)}
        >
          <option value="team1">Team 1</option>
          <option value="team2">Team 2</option>
        </select>

        <button type="submit">Add team member</button>
      </form>
    </div>
  );
}