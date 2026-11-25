import { Component, OnInit, OnDestroy } from '@angular/core';
import { UsersService } from './users.service';
import { Subscription } from 'rxjs';

@Component({
    selector: 'app-root',
    templateUrl: './users.component.html',
    standalone: false
})
export class UsersComponent implements OnInit, OnDestroy {
    usersList: string[]=[];
    private usersListSub!: Subscription;
    
    constructor(private uService: UsersService) {}

    ngOnInit() {
        this.usersList=this.uService.getUsers();
        this.usersListSub = this.uService.usersChanged.subscribe(newUsers=>{
            this.usersList=newUsers;
        });
    }

    onDeleteUser(user: string): void {
        this.uService.removeUser(user);
    }

    ngOnDestroy(){
        this.usersListSub.unsubscribe();
    }
}