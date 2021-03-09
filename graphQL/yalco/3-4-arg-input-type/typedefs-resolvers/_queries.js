const { gql } = require('apollo-server')

const typeDefs = gql`
    type Query {
        people: [People]
        peopleFiltered(
            team: Int, 
            sex: Sex, 
            blood_type: BloodType, 
            from: String
            ): [People]
            peoplePaginated(
                page: Int!,
                per_page: Int!,
                team: Int, 
                sex: Sex, 
                blood_type: BloodType, 
                from: String
            ): [People]
            equipments: [Equipment]
            equipmentAdvs: [EquipmentAdv]
            softwares: [Software]
        software: Software
        supplies: [Supply]
        givens: [Given]
    }
`

module.exports = typeDefs