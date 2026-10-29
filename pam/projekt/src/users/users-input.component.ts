import { Component, Output, EventEmitter } from "@angular/core";

@Component({
    selector: 'app-user-input',
    templateUrl: './users-input.component.html',
    styleUrls: ['./users-input.component.css'],
    standalone: false
})
/*export class UsersInputComponent {
    onCreateUser(userName:string ): void{
        console.log('utworzono uzytkownika!' + userName);
    }
}*/
export class UsersInputComponent {
    @Output() userCreated = new EventEmitter<string>();
    enteredUserName: string = '';
    onCreateUser(): void{
        console.log('utworzono uzytkownika!' + this.enteredUserName);
        this.userCreated.emit(this.enteredUserName)
        this.enteredUserName= '';
    }
}