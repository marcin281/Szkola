
"use client";

import { useRouter } from "next/navigation";

export default function StatusPage() {
  const router = useRouter();

  function handleSubmit(e: React.FormEvent<HTMLFormElement>) {
    e.preventDefault();
    const haslo = new FormData(e.currentTarget).get("haslo");

    if (haslo === "zaq1@WSX") {
      localStorage.setItem("killed", "true");
      alert("Potwierdzono likwidację");
      router.push("../status");
    } else {
      alert("Błędne hasło");
    }
  }

  return (
    <>
      <div className="kill-content">
  <h1>Potwierdź likwidację</h1>

  <form onSubmit={handleSubmit}>
    <input name="haslo" type="password" placeholder="Wprowadź hasło" />
    <button type="submit">Potwierdź</button>
  </form>
</div>
    </>
  );
}
