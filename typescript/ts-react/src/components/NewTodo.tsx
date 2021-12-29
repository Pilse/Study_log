import React, { FC, FormEvent, useRef } from 'react';

import './NewTodo.css'

interface NewTodoProps {
  onAddTodo: (todoText: string) => void;
}

const NewTodo: FC<NewTodoProps> = ({ onAddTodo }) => {
  const textInputRef = useRef<HTMLInputElement>(null);

  const todoSubmitHandler = (event: FormEvent) => {
    event.preventDefault();
    const enteredText = textInputRef.current!.value;
    onAddTodo(enteredText);

    textInputRef.current!.value = '';
  };

  return (
    <form onSubmit={todoSubmitHandler}>
      <div>
        <label htmlFor="todo-text">Todo Text</label>
        <input type="text" id="todo-text" ref={textInputRef}/>
      </div>
      <button type="submit">ADD TODO</button>
    </form>
  )
}

export default NewTodo;