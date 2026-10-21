
using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace WpfApp1
{
    public partial class MainWindow : Window
    {
        private readonly List<TaskItem> tasks = new List<TaskItem>();

        public MainWindow()
        {
            InitializeComponent();

            DateBlock.Text = DateTime.Now
                .ToString("dddd, d MMMM yyyy")
                .ToUpper();

            tasks.Add(new TaskItem("Zrobić sobie dobrą kawę", true));
            tasks.Add(new TaskItem("Ogarnąć najważniejsze sprawy", false));
            tasks.Add(new TaskItem("Znaleźć chwilę dla siebie", false));

            RenderTasks();
            UpdateStats();
        }

        private void AddTask(object sender, RoutedEventArgs e)
        {
            string text = TaskInput.Text.Trim();

            if (string.IsNullOrWhiteSpace(text))
            {
                TaskInput.Focus();
                return;
            }

            tasks.Add(new TaskItem(text, false));

            TaskInput.Clear();
            RenderTasks();
            UpdateStats();

            TaskInput.Focus();
        }

        private void TaskInputKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                AddTask(sender, e);
            }
        }

        private void RenderTasks()
        {
            TasksPanel.Children.Clear();

            if (tasks.Count == 0)
            {
                TextBlock emptyMessage = new TextBlock
                {
                    Text = "Na razie pusto. Możesz chwilę odetchnąć.",
                    FontSize = 13,
                    Foreground = new SolidColorBrush(
                        Color.FromRgb(133, 138, 128)),
                    TextWrapping = TextWrapping.Wrap,
                    Margin = new Thickness(10, 18, 10, 18),
                    HorizontalAlignment = HorizontalAlignment.Center
                };

                TasksPanel.Children.Add(emptyMessage);
                return;
            }

            foreach (TaskItem task in tasks)
            {
                Border row = new Border
                {
                    Background = task.IsDone
                        ? new SolidColorBrush(Color.FromRgb(246, 247, 241))
                        : Brushes.Transparent,
                    CornerRadius = new CornerRadius(8),
                    Padding = new Thickness(10, 9, 8, 9),
                    Margin = new Thickness(0, 2, 0, 3)
                };

                Grid layout = new Grid();

                layout.ColumnDefinitions.Add(
                    new ColumnDefinition { Width = new GridLength(34) });

                layout.ColumnDefinitions.Add(
                    new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });

                layout.ColumnDefinitions.Add(
                    new ColumnDefinition { Width = GridLength.Auto });

                CheckBox checkBox = new CheckBox
                {
                    IsChecked = task.IsDone,
                    VerticalAlignment = VerticalAlignment.Center,
                    HorizontalAlignment = HorizontalAlignment.Left,
                    Cursor = Cursors.Hand,
                    ToolTip = "Oznacz jako wykonane"
                };

                Grid.SetColumn(checkBox, 0);

                TextBlock taskText = new TextBlock
                {
                    Text = task.Name,
                    FontSize = 13,
                    Foreground = task.IsDone
                        ? new SolidColorBrush(Color.FromRgb(145, 151, 138))
                        : new SolidColorBrush(Color.FromRgb(38, 53, 47)),
                    TextWrapping = TextWrapping.Wrap,
                    VerticalAlignment = VerticalAlignment.Center,
                    Margin = new Thickness(2, 0, 8, 0)
                };

                if (task.IsDone)
                {
                    taskText.TextDecorations = TextDecorations.Strikethrough;
                }

                Grid.SetColumn(taskText, 1);

                Button deleteButton = new Button
                {
                    Content = "×",
                    FontSize = 19,
                    Foreground = new SolidColorBrush(
                        Color.FromRgb(151, 151, 140)),
                    Background = Brushes.Transparent,
                    BorderThickness = new Thickness(0),
                    Width = 30,
                    Height = 30,
                    Cursor = Cursors.Hand,
                    ToolTip = "Usuń zadanie"
                };

                Grid.SetColumn(deleteButton, 2);

                checkBox.Checked += (s, e) =>
                {
                    task.IsDone = true;
                    taskText.TextDecorations = TextDecorations.Strikethrough;
                    taskText.Foreground = new SolidColorBrush(
                        Color.FromRgb(145, 151, 138));

                    row.Background = new SolidColorBrush(
                        Color.FromRgb(246, 247, 241));

                    UpdateStats();
                };

                checkBox.Unchecked += (s, e) =>
                {
                    task.IsDone = false;
                    taskText.TextDecorations = null;
                    taskText.Foreground = new SolidColorBrush(
                        Color.FromRgb(38, 53, 47));

                    row.Background = Brushes.Transparent;

                    UpdateStats();
                };

                deleteButton.Click += (s, e) =>
                {
                    tasks.Remove(task);
                    RenderTasks();
                    UpdateStats();
                };

                layout.Children.Add(checkBox);
                layout.Children.Add(taskText);
                layout.Children.Add(deleteButton);

                row.Child = layout;

                TasksPanel.Children.Add(row);
            }
        }

        private void UpdateStats()
        {
            int total = tasks.Count;
            int completed = tasks.FindAll(t => t.IsDone).Count;

            int percentage = total == 0
                ? 0
                : (int)Math.Round(completed * 100.0 / total);

            TaskCountBlock.Text = completed + " z " + total;

            ProgressPercent.Text = percentage + "%";
            TaskProgress.Value = percentage;

            if (total == 0)
            {
                ProgressText.Text = "Czysta karta. Co dziś zaplanujesz?";
            }
            else if (completed == total)
            {
                ProgressText.Text = "Gotowe! Wszystko zrobione.";
            }
            else if (completed == 0)
            {
                ProgressText.Text = "Spokojnie, zacznij od jednej rzeczy.";
            }
            else
            {
                ProgressText.Text = "Dobra robota. Tak trzymaj!";
            }
        }

        private void ClearCompleted(object sender, RoutedEventArgs e)
        {
            tasks.RemoveAll(t => t.IsDone);

            RenderTasks();
            UpdateStats();
        }

        private void FocusTasks(object sender, RoutedEventArgs e)
        {
            TaskInput.Focus();
        }

        private class TaskItem
        {
            public string Name { get; }
            public bool IsDone { get; set; }

            public TaskItem(string name, bool isDone)
            {
                Name = name;
                IsDone = isDone;
            }
        }
    }
}