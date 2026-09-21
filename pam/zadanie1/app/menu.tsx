import Logo from "./logo";
import MenuLink from "./menulink";

export default function Menu() {
    return (
        <div className="menu">
            <Logo />

            <div className="content">
                <h1>tytul</h1>
                <h3>podtytul</h3>

                <div className="links">
                    <MenuLink
                        text1="https://pl.wikipedia.org/wiki/Wikipedia"
                        text2="wikipedia"
                    />

                    <MenuLink
                        text1="https://www.google.com/"
                        text2="google"
                    />

                    <MenuLink
                        text1="https://www.youtube.com/"
                        text2="youtube"
                    />
                </div>
            </div>
        </div>
    );
}
