import Header from "./header";
import Main from "./main";
import Footer from "./footer";

export default function Page() {
  return (
    <div className="dashboard">
      <Header />
      <Main />
      <Footer />
    </div>
  );
}