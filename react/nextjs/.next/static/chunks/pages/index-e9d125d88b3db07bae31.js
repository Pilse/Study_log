_N_E=(window.webpackJsonp_N_E=window.webpackJsonp_N_E||[]).push([[7],{"20a2":function(e,n,t){e.exports=t("nOHt")},RNiq:function(e,n,t){"use strict";t.r(n);var r=t("o0o1"),o=t.n(r);function a(e,n,t,r,o,a,c){try{var i=e[a](c),u=i.value}catch(s){return void t(s)}i.done?n(u):Promise.resolve(u).then(r,o)}var c=t("nKUr"),i=(t("q1tI"),t("YFqc")),u=t.n(i),s=t("20a2"),l=t.n(s);function f(e){return Object(c.jsxs)("div",{children:[Object(c.jsxs)("h1",{children:["The Main Page - ",e.appName]}),Object(c.jsxs)("p",{children:["Go to"," ",Object(c.jsx)(u.a,{href:"/auth",children:Object(c.jsx)("a",{children:"Auth"})})]}),Object(c.jsx)("button",{onClick:function(){return l.a.push("/auth")},children:"Go to Auth"})]})}f.getInitialProps=function(){var e,n=(e=o.a.mark((function e(n){var t;return o.a.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:return t=new Promise((function(e,n){setTimeout((function(){e({appName:"Super "})}),1e3)})),e.abrupt("return",t);case 2:case"end":return e.stop()}}),e)})),function(){var n=this,t=arguments;return new Promise((function(r,o){var c=e.apply(n,t);function i(e){a(c,r,o,i,u,"next",e)}function u(e){a(c,r,o,i,u,"throw",e)}i(void 0)}))});return function(e){return n.apply(this,arguments)}}();n.default=f},YFqc:function(e,n,t){e.exports=t("cTJO")},cTJO:function(e,n,t){"use strict";var r=t("J4zp"),o=t("284h");n.__esModule=!0,n.default=void 0;var a=o(t("q1tI")),c=t("elyg"),i=t("nOHt"),u=t("vNVm"),s={};function l(e,n,t,r){if(e&&(0,c.isLocalURL)(n)){e.prefetch(n,t,r).catch((function(e){0}));var o=r&&"undefined"!==typeof r.locale?r.locale:e&&e.locale;s[n+"%"+t+(o?"%"+o:"")]=!0}}var f=function(e){var n=!1!==e.prefetch,t=(0,i.useRouter)(),o=t&&t.pathname||"/",f=a.default.useMemo((function(){var n=(0,c.resolveHref)(o,e.href,!0),t=r(n,2),a=t[0],i=t[1];return{href:a,as:e.as?(0,c.resolveHref)(o,e.as):i||a}}),[o,e.href,e.as]),p=f.href,d=f.as,v=e.children,h=e.replace,b=e.shallow,m=e.scroll,w=e.locale;"string"===typeof v&&(v=a.default.createElement("a",null,v));var y=a.Children.only(v),g=y&&"object"===typeof y&&y.ref,_=(0,u.useIntersection)({rootMargin:"200px"}),E=r(_,2),j=E[0],L=E[1],M=a.default.useCallback((function(e){j(e),g&&("function"===typeof g?g(e):"object"===typeof g&&(g.current=e))}),[g,j]);(0,a.useEffect)((function(){var e=L&&n&&(0,c.isLocalURL)(p),r="undefined"!==typeof w?w:t&&t.locale,o=s[p+"%"+d+(r?"%"+r:"")];e&&!o&&l(t,p,d,{locale:r})}),[d,p,L,w,n,t]);var N={ref:M,onClick:function(e){y.props&&"function"===typeof y.props.onClick&&y.props.onClick(e),e.defaultPrevented||function(e,n,t,r,o,a,i,u){("A"!==e.currentTarget.nodeName||!function(e){var n=e.currentTarget.target;return n&&"_self"!==n||e.metaKey||e.ctrlKey||e.shiftKey||e.altKey||e.nativeEvent&&2===e.nativeEvent.which}(e)&&(0,c.isLocalURL)(t))&&(e.preventDefault(),null==i&&(i=r.indexOf("#")<0),n[o?"replace":"push"](t,r,{shallow:a,locale:u,scroll:i}))}(e,t,p,d,h,b,m,w)},onMouseEnter:function(e){(0,c.isLocalURL)(p)&&(y.props&&"function"===typeof y.props.onMouseEnter&&y.props.onMouseEnter(e),l(t,p,d,{priority:!0}))}};if(e.passHref||"a"===y.type&&!("href"in y.props)){var O="undefined"!==typeof w?w:t&&t.locale,x=t&&t.isLocaleDomain&&(0,c.getDomainLocale)(d,O,t&&t.locales,t&&t.domainLocales);N.href=x||(0,c.addBasePath)((0,c.addLocale)(d,O,t&&t.defaultLocale))}return a.default.cloneElement(y,N)};n.default=f},vNVm:function(e,n,t){"use strict";var r=t("J4zp");n.__esModule=!0,n.useIntersection=function(e){var n=e.rootMargin,t=e.disabled||!c,u=(0,o.useRef)(),s=(0,o.useState)(!1),l=r(s,2),f=l[0],p=l[1],d=(0,o.useCallback)((function(e){u.current&&(u.current(),u.current=void 0),t||f||e&&e.tagName&&(u.current=function(e,n,t){var r=function(e){var n=e.rootMargin||"",t=i.get(n);if(t)return t;var r=new Map,o=new IntersectionObserver((function(e){e.forEach((function(e){var n=r.get(e.target),t=e.isIntersecting||e.intersectionRatio>0;n&&t&&n(t)}))}),e);return i.set(n,t={id:n,observer:o,elements:r}),t}(t),o=r.id,a=r.observer,c=r.elements;return c.set(e,n),a.observe(e),function(){c.delete(e),a.unobserve(e),0===c.size&&(a.disconnect(),i.delete(o))}}(e,(function(e){return e&&p(e)}),{rootMargin:n}))}),[t,n,f]);return(0,o.useEffect)((function(){if(!c&&!f){var e=(0,a.requestIdleCallback)((function(){return p(!0)}));return function(){return(0,a.cancelIdleCallback)(e)}}}),[f]),[d,f]};var o=t("q1tI"),a=t("0G5g"),c="undefined"!==typeof IntersectionObserver;var i=new Map},vlRD:function(e,n,t){(window.__NEXT_P=window.__NEXT_P||[]).push(["/",function(){return t("RNiq")}])}},[["vlRD",0,2,1]]]);