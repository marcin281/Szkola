import { Component, Input } from "@angular/core";

@Component({
  selector: 'app-users',
  templateUrl: './users.component.html',
  standalone: false
})
export class UsersComponent {
  @Input() usersList: string[] = [];
}
