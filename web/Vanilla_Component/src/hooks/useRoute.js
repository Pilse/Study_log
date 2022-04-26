function useRoute() {
  const path = () => location.pathname;

  const navigate = (url) => {
    history.pushState("state", null, url);
    dispatchEvent(new Event("popstate"));
  };

  return { path, navigate };
}

export default useRoute;
