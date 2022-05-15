function useRoute() {
  const path = () => location.pathname;

  const navigate = (url) => {
    history.pushState({}, url, url);
    const event = new CustomEvent("popstate");

    window.dispatchEvent(event);
  };

  return { path, navigate };
}

export default useRoute;
