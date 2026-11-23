
"use client";

import { useState, useEffect } from "react";

export default function Team() {
  const [crew, setCrew] = useState<any[]>([]);
  const [team, setTeam] = useState<any[]>([]);
  const [selectedTeam, setSelectedTeam] = useState("team1");
  const [selectedMember, setSelectedMember] = useState("");
  const [showModal, setShowModal] = useState(false);

  useEffect(() => {
    setCrew(JSON.parse(localStorage.getItem("crew") || "[]"));
    setTeam(JSON.parse(localStorage.getItem("team") || "[]"));
  }, []);

  const openModal = (teamName: string) => {
    setSelectedTeam(teamName);
    setSelectedMember("");
    setShowModal(true);
  };

  const addMember = () => {
    if (!selectedMember) return;

    const updatedTeams = team.filter(
      (member) => member.name !== selectedMember
    );

    updatedTeams.push({
      name: selectedMember,
      team: selectedTeam
    });

    localStorage.setItem("team", JSON.stringify(updatedTeams));
    setTeam(updatedTeams);
    setSelectedMember("");
    setShowModal(false);
  };

  return (
    <div className="team-content">
      <h2>TEAMS</h2>

      <div className="teams-list">

        <section className="team-box">
          <h3>
            TEAM 1
            <button onClick={() => openModal("team1")}>
              + ADD
            </button>
          </h3>

          <ol>
            {team
              .filter((member) => member.team === "team1")
              .map((member, i) => (
                <li key={i}>
                  <span>{member.name}</span>
                </li>
              ))}
          </ol>
        </section>

        <section className="team-box">
          <h3>
            TEAM 2
            <button onClick={() => openModal("team2")}>
              + ADD
            </button>
          </h3>

          <ol>
            {team
              .filter((member) => member.team === "team2")
              .map((member, i) => (
                <li key={i}>
                  <span>{member.name}</span>
                </li>
              ))}
          </ol>
        </section>

      </div>

      {showModal && (
        <div
          className="modal-overlay"
          onClick={() => setShowModal(false)}
        >
          <div
            className="modal"
            onClick={(e) => e.stopPropagation()}
          >
            <h2>ADD CREW MEMBER</h2>

            <select
              value={selectedMember}
              onChange={(e) => setSelectedMember(e.target.value)}
            >
              <option value="">Select crew member</option>

              {crew.map((member, i) => (
                <option key={i} value={member.name}>
                  {member.name}
                </option>
              ))}
            </select>

            <select
              value={selectedTeam}
              onChange={(e) => setSelectedTeam(e.target.value)}
            >
              <option value="team1">Team 1</option>
              <option value="team2">Team 2</option>
            </select>

            <div className="modal-buttons">
              <button onClick={addMember}>
                ADD
              </button>

              <button
                className="cancel"
                onClick={() => setShowModal(false)}
              >
                CANCEL
              </button>
            </div>
          </div>
        </div>
      )}
    </div>
  );
}