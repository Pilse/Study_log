const hamburgerContainer = document.querySelector("#header__main-nav");
const hamburger = document.querySelector(".header__main-nav--hamburger");
const links = document.querySelectorAll(".header__main-nav--links li");

let idx = 0;

hamburger.addEventListener("click", () => {
  hamburgerContainer.classList.toggle("clicked");

  if (hamburgerContainer.classList.contains("clicked")) {
    let show = setInterval(() => {
      links[idx++].classList.add("show");
      if (idx === links.length - 1) {
        clearInterval(show);
      }
    }, 100);
  } else {
    links.forEach((link) => link.classList.remove("show"));
    idx = 0;
  }
});
