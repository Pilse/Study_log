import React from 'react';

const currentYear = new Date().getFullYear();

const Footer =function() {
    return(
        <footer>
            <p>Copyright &copy; {currentYear}</p>
        </footer>
    )
}

export default Footer;