import { render, screen } from "../../../test-utils/testing-library-utils";
import userEvent from "@testing-library/user-event";
import Options from "../Options";
import OrderEntry from "../OrderEntry";

test("update scroop subtotal when scoops change", async () => {
  render(<Options optionType="scoops" />);

  const scoopsSubtotal = screen.getByText("Scoops total: ", { exact: false });
  expect(scoopsSubtotal).toHaveTextContent("0");

  const vanillaInput = await screen.findByRole("spinbutton", {
    name: "Vanilla",
  });
  await userEvent.clear(vanillaInput);
  await userEvent.type(vanillaInput, "1");
  expect(scoopsSubtotal).toHaveTextContent("2");

  const chocolateInput = await screen.findByRole("spinbutton", {
    name: "Chocolate",
  });
  await userEvent.clear(chocolateInput);
  await userEvent.type(chocolateInput, "2");
  expect(scoopsSubtotal).toHaveTextContent("6");
});

test("update topping subtotal when toppings change", async () => {
  render(<Options optionType="toppings" />);

  const toppingsTotal = screen.getByText("Toppings total:", { exact: false });
  expect(toppingsTotal).toHaveTextContent("0");

  const CherriesCheckbox = await screen.findByRole("checkbox", {
    name: "Cherries",
  });

  await userEvent.click(CherriesCheckbox);
  expect(toppingsTotal).toHaveTextContent("1.5");

  const hotFudgeCheckbox = screen.getByRole("checkbox", { name: "Hot fudge" });
  await userEvent.click(hotFudgeCheckbox);
  expect(toppingsTotal).toHaveTextContent("3");

  await userEvent.click(hotFudgeCheckbox);
  expect(toppingsTotal).toHaveTextContent("1.5");
});

describe("grand total", () => {
  test("grand total starts at $0.00", () => {
    render(<OrderEntry />);

    const grandTotal = screen.getByText("Grand total:");

    expect(grandTotal).toHaveTextContent("0");
  });

  test("grand total updates properly if scoop is added first", async () => {
    render(<OrderEntry />);

    const grandTotal = screen.getByText("Grand total:");
    const vanillaInput = await screen.findByRole("spinbutton", {
      name: "Vanilla",
    });
    await userEvent.clear(vanillaInput);
    await userEvent.type("2");

    expect(grandTotal).toHaveTextContent("4");

    const cherriesCheckbox = await screen.findByRole("checkbox", {
      name: "Cherries",
    });
    await userEvent.click(cherriesCheckbox);

    expect(grandTotal).toHaveTextContent("5.5");
  });

  test("grand total updates properly if topping is added first", async () => {
    render(<OrderEntry />);

    const grandTotal = screen.getByRole("heading", { name: /Grand total:/i });
    const cherriesCheckbox = await screen.findByRole("checkbox", {
      name: "Cherries",
    });
    await userEvent.click(cherriesCheckbox);

    expect(grandTotal).toHaveTextContent("1.5");

    const vanillaInput = await screen.findByRole("spinbutton", {
      name: "Vanilla",
    });
    await userEvent.clear(vanillaInput);
    await userEvent.type(vanillaInput, "2");

    expect(grandTotal).toHaveTextContent("5.5");
  });

  test("grand total updates properly if item is removed", async () => {
    render(<OrderEntry />);

    const grandTotal = screen.getByText("Grand total:");

    const vanillaInput = await screen.findByRole("spinbutton", {
      name: "Vanilla",
    });
    const cherriesCheckbox = await screen.findByRole("checkbox", { name: "Cherries" });

    await userEvent.clear(vanillaInput);
    await userEvent.type(vanillaInput, "1");

    expect(grandTotal).toHaveTextContent("3.5");

    await userEvent.click(cherriesCheckbox);

    expect(grandTotal).toHaveTextContent("2");
  });
});
