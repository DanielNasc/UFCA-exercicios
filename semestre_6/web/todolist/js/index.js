const task_input = document.getElementById("task");
const tasks_list = document.getElementById("tasks");

let tasks = [];

function add_task(event) {
    event.preventDefault();

    const task = task_input.value;
    if (task.trim()  === "" || tasks.includes(task)) {
        task_input.value = "";
        return;
    }

    const task_element = document.createElement("input");
    task_element.setAttribute("type", "checkbox");
    task_element.setAttribute("id", task);
    task_element.setAttribute("name", task);
    task_element.setAttribute("value", task);
    task_element.setAttribute("class", "task");

    const label = document.createElement("label");
    label.setAttribute("for", task);
    label.innerText = task;

    const div_task = document.createElement("div");
    div_task.appendChild(task_element);
    div_task.appendChild(label);
    div_task.setAttribute("class", "task-container")

    tasks_list.appendChild(div_task)

    tasks.push(task);
    task_input.value = "";
}