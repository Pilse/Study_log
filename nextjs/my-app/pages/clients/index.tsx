import { NextPage } from "next";
import Link from "next/link";

const ClientPage: NextPage = () => {
  const clients =[
    {id: 'max', name: 'Maximlian'},
    {id: 'manu', name: 'Manuel'},
  ]

  return (
    <div>
      <h1> Client Page </h1>

      <ul>
        {clients.map(client => 
          <li key={client.id}>
            <Link href={{
              pathname: '/clients/id',
              query: {id: client.id}
            }}>{client.name}</Link>
          </li>
        )}
      </ul>
    </div>
  )
}

export default ClientPage;