import Header from "./header";
import Footer from "./footer";
import Main from "./main"

export default function Home() {
  return (
    <>
      <div className="flex">
        <Header />
        <Main />
        <Footer />
      </div>
    </>
  );
}
