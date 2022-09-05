import Link from "next/link";
import React from "react";

import classes from "./button.module.css";

type ButtonProps = {
  link?: string;
  onClick?: () => {};
  children: React.ReactNode;
};

const Button = ({ link, onClick, children }: ButtonProps) => {
  if (link)
    return (
      <Link href={link}>
        <a className={classes.btn}>{children}</a>
      </Link>
    );

  return (
    <button className={classes.btn} onClick={onClick}>
      {children}
    </button>
  );
};

export default Button;
