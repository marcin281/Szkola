import Menu from "./menu";
import Main from "./main";
import Aside from "./aside";
import Footer from "./footer";

export default function Home() {
  return (
    <>
      <Menu />

      <div className="flex">
        <Aside />
        <Main />
      </div>

    <Footer />
    </>
  );
}
