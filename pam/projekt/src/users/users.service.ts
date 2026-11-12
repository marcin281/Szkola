import { Injectable } from "@angular/core";

@Injectable({
    providedIn: 'root'
})
export class UsersService {

    users: string[] = ['Maks Rajski', 'Oliwier Strąk'];

    addUser(name: string): void {
        this.users.push(name);
    }

    removeUser(name: string): void {
        console.log('delete: '+name);
        if(this.users.indexOf(name)!==-1){
            const index: number=this.users.indexOf(name);
            const removed=this.users.splice(index,1);
            console.log('usuniete: '+removed)
        }
    }
}