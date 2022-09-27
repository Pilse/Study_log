import Options from "./Options";

export default function OrderEntry() {
  return (
    <div>
      <Options optionType="scoops" />
      <Options optionType="topping" />
    </div>
  );
}
