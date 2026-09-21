import Link from 'next/link'
 
export default function NotFound() {
  return (
    <div>
      <h2>Nie znaleziono 404</h2>
      <p>Nie znaleziono podanej strony</p>
      <Link href="/">Powróć</Link>
    </div>
  )
}