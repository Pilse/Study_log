const graphql = require('graphql');
const fetch = require('node-fetch');

const {
    GraphQLObjectType,
    GraphQLString,
    GraphQLInt,
    GraphQLSchema,
    GraphQLList,
    GraphQLNonNull
} = graphql;

const CompanyType = new GraphQLObjectType({
    name: 'Company',
    fields: () => ({
        id: { type: GraphQLString },
        name: { type: GraphQLString },
        description: { type: GraphQLString },
        users: {
            type: new GraphQLList(UserType),
            resolve(parentValue, args) {
                return fetch(`http://localhost:3000/companies/${parentValue.id}/users`)
                    .then(res => res.json())
            }
        }
    })
});

const UserType = new GraphQLObjectType({
    name: 'User',
    fields: () => ({
        id: { type: GraphQLString },
        firstName: { type: GraphQLString },
        age: { type: GraphQLInt },
        company: {
            type: CompanyType,
            resolve(parentValue, args) {
                return fetch(`http://localhost:3000/companies/${parentValue.companyId}`)
                    .then(res => res.json());
            }
        }
    })
});

const mutation = new GraphQLObjectType({
    name: 'Mutation',
    fields: {
        addUser: {
            type: UserType,
            args: {
                firstName: { type: new GraphQLNonNull(GraphQLString) },
                age: { type: new GraphQLNonNull(GraphQLInt) },
                companyId: { type: GraphQLString }
            },
            resolve(parentValue, args) {
                return fetch('http://localhost:3000/users', {
                    method: 'POST',
                    body: JSON.stringify(args),
                    headers: {
                        'Content-Type': 'application/json'
                    }

                })
                    .then(res => res.json());
            }
        },
        deleteUser: {
            type: UserType,
            args: {
                id: { type: new GraphQLNonNull(GraphQLString) }
            },
            resolve(parentValue, args) {
                return fetch(`http://localhost:3000/users/${args.id}`, {
                    method: 'DELETE'
                })
                    .then(res => res.json());
            }
        },
        editUser: {
            type: UserType,
            args: {
                id: { type: new GraphQLNonNull(GraphQLString) },
                firstName: { type: GraphQLString },
                age: { type: GraphQLInt },
                companyId: { type: GraphQLString }
            },
            resolve(parentValue, args) {
                return fetch(`http://localhost:3000/users/${args.id}`, {
                    method: 'PATCH',
                    body: JSON.stringify(args),
                    headers: {
                        'Content-Type': 'application/json'
                    }
                })
                    .then(res => res.json());
            }
        }
    }
})

const RootQuery = new GraphQLObjectType({
    name: 'RootQueryType',
    fields: {
        user: {
            type: UserType,
            args: { id: { type: GraphQLString } },
            resolve(parentValue, args) {
                return fetch(`http://localhost:3000/users/${args.id}`)
                    .then(res => res.json())
            }
        },
        company: {
            type: CompanyType,
            args: { id: { type: GraphQLString } },
            resolve(parentValue, args) {
                return fetch(`http://localhost:3000/companies/${args.id}`)
                    .then(res => res.json())
            }
        }
    }
});

module.exports = new GraphQLSchema({
    query: RootQuery,
    mutation
});