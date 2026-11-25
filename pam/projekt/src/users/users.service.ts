import { Injectable } from "@angular/core";
import { Subject } from 'rxjs';

@Injectable({
    providedIn: 'root'
})
export class UsersService {

    private users: string[] = ['Maks Rajski', 'Oliwier Strąk'];
    usersChanged = new Subject<string[]>();

    getUsers(): string[]{
        return this.users;
    }

    addUser(name: string): void {
        if(!this.users.includes(name)){
            this.users.push(name);
            this.usersChanged.next(this.users)
        }
    }

    removeUser(name: string): void {
        if(this.users.includes(name)){
            const index = this.users.indexOf(name);
            this.users.splice(index, 1);
            this.usersChanged.next(this.users);
        }
    }
}