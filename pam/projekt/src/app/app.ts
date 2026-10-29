import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  standalone: false,
  styleUrl: './app.css',
  templateUrl: './app.html',
})
export class App {
  users: string[] = ['Jan', 'Mścisława', 'Maria'];
  
  onUserCreated(name: string): void{
    this.users=[...this.users,name]
    }
}
