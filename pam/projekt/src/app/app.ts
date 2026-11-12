import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  standalone: false,
  styleUrl: './app.css',
  templateUrl: './app.html',
})
export class App {
  users: string[] = ["Maks Rajski", "Oliwiet Strąk"];

  onUserCreated(user: { name: string; lastname: string }): void {
    const newUser = `${user.name} ${user.lastname}`;

    if (!this.users.includes(newUser)) {
      this.users = [...this.users, newUser];
    }
  }

  onUserDelete(user: string): void {
    this.users = this.users.filter(u => u !== user);
  }
}