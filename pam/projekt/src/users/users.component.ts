import { Component, Output, EventEmitter, OnInit } from '@angular/core';
import { UsersService } from './users.service';

@Component({
    selector: 'app-root',
    templateUrl: './users.component.html',
    standalone: false
})
export class UsersComponent implements OnInit {
    usersList: string[];
    @Output() userDeleted = new EventEmitter<string>();

    constructor(private uService: UsersService) {
        this.usersList = uService.users
    }

    ngOnInit() {
        this.usersList=this.uService.users;
    }

    onDeleteUser(user: string): void {
        this.uService.deleteUser(user);
        this.usersList = this.uService.users;
    }
}