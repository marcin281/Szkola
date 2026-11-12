import { Component, Output, EventEmitter } from "@angular/core";
import { UsersService } from "./users.service";

@Component({
    selector: 'app-user-input',
    templateUrl: './users-input.component.html',
    styleUrls: ['./users-input.component.css'],
    standalone: false
})
export class UsersInputComponent {
    enteredUserName: string = '';
    enteredUserLastName: string = '';

    constructor(private uService: UsersService){}
    onCreateUser(): void{
        console.log('Dodano uzytkownika: ' +this.enteredUserName+' '+this.enteredUserLastName);
        this.uService.addUser(this.enteredUserName+' '+this.enteredUserLastName);
        this.enteredUserName=this.enteredUserLastName='';
    }
}