"use client";

import { useState, useEffect} from "react";
import Link from "next/link";
export default function CrewHealth() {

  const [crew, setCrew] = useState<any[]>([]);

  useEffect(() => {
    setCrew(JSON.parse(localStorage.getItem("crew") || "[]"));
  }, []);
  return (
    <div>
      <h2>CREW HEALTH</h2>

        <form className="crew-form" onSubmit={(e) => {
            e.preventDefault();
            }}>
            <select name="choice" id="choice">
                {crew.map((member, i) => (
                    <option className="crew-member" key={i}>
                        <p>{member.name}</p>
                    </option>
                ))}
            </select>
        </form>
    </div>
  );
}
//select gdzie bedzie mozna wybrac uzytkownika,pobraz z local storage, nie dopuscic treningu innej osoby na ta sama godzine i dzien, wybor pokoju (treningu) oddechowego lub fizycznego, najpierw wyberia sie uzytjkownika i potem pokoj, wtedy sie wyswietla kalendarz, 5 min przerwy miedzy terminami, np jest  zarezerwowane 8.20-9,00 nie moge zarezerowac 0.00-9.30 tylko od 9.05-9.30