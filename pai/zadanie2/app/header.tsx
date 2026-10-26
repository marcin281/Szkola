import Link from "next/link";

export default function Header() {
  return (
    <header className="header">
      <h1>APOLLO 17</h1>

      <nav className="nav">
        <div className="nav-item">
          <a href="/status">STATUS</a>
        </div>

        <div className="nav-item">
          <a href="#">OXYGEN</a>
        </div>

        <div className="nav-item">
          <a href="#">CREW</a>
        </div>
      </nav>
    </header>
  );
}