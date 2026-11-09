import MissionTime from "./MissionTime";
import "./globals.css";

export default function Main() {
  return (
    <main className="main">
      <img
        src="spacex.png"
        className="logo"
        alt="SpaceX"
      />

      <MissionTime />
    </main>
  );
}