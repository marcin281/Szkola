import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { UsersComponent } from '../users/users.component';
import { UsersInputComponent } from '../users/users-input.component';

const routes: Routes = [
  {path: '', component: UsersComponent},
  {path: 'add', component: UsersInputComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
