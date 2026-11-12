import { Injectable } from "@angular/core";

@Injectable({
    providedIn: 'root'
})
export class UsersService {

    users: string[] = ['Maks Rajski', 'Oliwier Strąk'];

    addUser(name: string): void {
        this.users.push(name);
    }

    deleteUser(user: string): void {
        this.users = this.users.filter(u => u !== user);
    }
}