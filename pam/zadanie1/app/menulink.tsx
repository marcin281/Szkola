export default function menu({text1, text2}: {text1:string, text2:string}) {
    return(
        <a href={text1}>{text2}</a>
    );
}