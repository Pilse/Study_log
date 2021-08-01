import React, { useState } from 'react'
import { CKEditor } from '@ckeditor/ckeditor5-react'
import ClassicEditor from '@ckeditor/ckeditor5-build-classic'

import './App.css'

const App = () => {
  const [data, setData] = useState()


  return (

    <div className="App">
      <h2>Using CKEditor 5 build in React</h2>
      <CKEditor
        editor={ ClassicEditor }
          data={data}
          onChange={ ( event, editor ) => {
              // const data = editor.getData();
              // console.log( { event, editor, data } );
              setData(editor.getData())
          }}
      />
      <div className="content" dangerouslySetInnerHTML={{__html: data}}></div>
    </div>
    

  )
}

export default App