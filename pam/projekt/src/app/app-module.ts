import { NgModule, provideBrowserGlobalErrorListeners } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { AppRoutingModule } from './app-routing-module';
import { App } from './app';
import { UsersComponent } from '../users/users.component';
import { UsersInputComponent } from '../users/users-input.component';
import { FormsModule } from '@angular/forms';
@NgModule({
  declarations: [
    App,
    UsersComponent,
    UsersInputComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule
  ],
  providers: [
    provideBrowserGlobalErrorListeners(),
  ],
  bootstrap: [App]
})
export class AppModule { }
