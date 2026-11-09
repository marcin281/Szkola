
"use client";

import { useState, useEffect } from "react";

export default function MissionTime() {
  const [now, setNow] = useState<Date | null>(null);

  useEffect(() => {
    setNow(new Date());

    const interval = setInterval(() => {
      setNow(new Date());
    }, 1000);

    return () => clearInterval(interval);
  }, []);

  if (!now) return null;

  const actualTime = now.toLocaleTimeString("en-GB", {
    timeZone: "UTC",
    hour: "2-digit",
    minute: "2-digit",
    second: "2-digit",
    hour12: false,
  });

  const nextOrbit = new Date(now);
  nextOrbit.setUTCHours(18, 0, 0, 0);

  if (now >= nextOrbit) {
    nextOrbit.setUTCDate(nextOrbit.getUTCDate() + 1);
  }

  const difference = nextOrbit.getTime() - now.getTime();

  const hours = Math.floor(difference / 3600000);
  const minutes = Math.floor((difference % 3600000) / 60000);
  const seconds = Math.floor((difference % 60000) / 1000);

  const format = (value: number) =>
    String(value).padStart(2, "0");

  return (
    <div className="mission-time">
      <div className="time-box">
        <span className="time-label">SPACE TIME (UTC)</span>
        <h1>{actualTime}</h1>
      </div>

      <div className="time-box">
        <span className="time-label">NEXT ORBIT (18:00 UTC)</span>
        <h1>
          {format(hours)}:{format(minutes)}:{format(seconds)}
        </h1>
      </div>
    </div>
  );
}
