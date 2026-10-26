
"use client";

import { useEffect, useState } from "react";
import Header from "../header";
import Footer from "../footer";

export default function StatusPage() {
  const [killed, setKilled] = useState(false);
  useEffect(() => {
    setKilled(localStorage.getItem("killed") === "true");
  }, []);

  function reviveWiktor() {
    localStorage.setItem("killed", "false");
    setKilled(false);
    alert("Wiktor został ożywiony!");
  }

  return (
    <div className="dashboard">
      <Header />

      <main className="status-content">
        <h2>STATUS</h2>

        <p>oxygen = true</p>
        <p>oxygen level = 78%</p>
        <p>wiktor alive = {!killed ? "true" : "false"}</p>

        <br />
        <a href="../kill">Unicestwij Wiktora</a>
        <br /><br />
        <button onClick={reviveWiktor}>
          Ożyw Wiktora
        </button>
      </main>

      <Footer />
    </div>
  );
}
