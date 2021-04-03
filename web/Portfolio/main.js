const hamburgerContainer = document.querySelector("#header__main-nav");
const hamburger = document.querySelector(".header__main-nav--hamburger");
const links = document.querySelectorAll(".header__main-nav--links li");
const works = document.querySelectorAll(".work__card img");

const aboutMe = document.querySelector("#about-me");
const aboutMeImg = document.querySelector(".about-me__img");
const aboutMeContent = document.querySelector(".about-me__content");
const service = document.querySelector("#services");
const services = document.querySelectorAll(".service");

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

window.addEventListener("scroll", (e) => {
  if (window.scrollY > showcase.offsetHeight / 10) {
    works.forEach((work) => work.classList.add("show"));
  } else {
    works.forEach((work) => work.classList.remove("show"));
  }
  if (aboutMeImg.getBoundingClientRect().top < 500) {
    aboutMeImg.classList.add("show");
    aboutMeContent.classList.add("show");
  } else {
    aboutMeImg.classList.remove("show");
    aboutMeContent.classList.remove("show");
  }
  console.log(service.getBoundingClientRect().top);
  if (service.getBoundingClientRect().top < 800) {
    services.forEach((service) => {
      service.classList.add("show");
    });
  } else {
    services.forEach((service) => {
      service.classList.remove("show");
    });
  }
});
