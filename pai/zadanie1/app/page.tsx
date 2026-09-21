import Main from "./main";
import Aside from "./aside";

export default function Home() {
  throw new Error("test");
  return (
    <>
      <div className="flex">
        <Aside />
        <Main />
      </div>
    </>
  );
}
