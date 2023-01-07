import { render, screen } from "@testing-library/react";
import userEvent from "@testing-libraray/user-event";

import App from "../App";

test("order phases for happy path", async () => {
  // render app
  render(<App />);

  // add ice cream scoops and toppings
  const vanillaScoop = await screen.findByRole("spinbutton", { name: "Vanillla" });
  const cherriesTopping = await screen.findByRole("checkbox", { name: "Cherries" });

  await userEvent.clear(vanillaScoop);
  await userEvent.type(vanillaScoop, "1");
  await userEvent.click(cherriesTopping);

  // find and click order button
  const orderButton = screen.getByRole("button", { name: "order sundae" });
  await userEvent.click(orderButton);

  // check summary information based on order
  const summaryHeading = screen.getByRole("heading", { name: "Order Summary" });
  expect(summaryHeading).toBeInTheDocument();

  const scoopsHeading = screen.getByRole("heading", { name: "Scoops: $6.00" });
  expect(scoopsHeading).toBeInTheDocument();

  const toppingsHeading = screen.getByRole("heading", { name: "Toppings: $1.50" });
  expect(toppingsHeading).toBeInTheDocument();

  // check summary option items
  expect(screen.getByText("1 Vanilla")).toBeInTheDocument();
  expect(screen.getByText("Cherries")).toBeInTheDocument();

  // accept terms and conditions and click button to confirm order
  const tcCheckBox = screen.getByRole("checkbox", {
    name: /terms and conditions/i,
  });
  await userEvent.click(tcCheckBox);

  const confirmOrderButton = screen.getByRole("button", {
    name: /confirm order/i,
  });

  await userEvent.click(confirmOrderButton);

  const loader = await screen.findByText("loading");
  expect(loader).toBeInTheDocument();

  const thankYouHeader = await screen.findByRole("heading", { name: /thank you/i });

  expect(thankYouHeader).toBeInTheDocument();
  expect(loader).not.toBeInTheDocument();

  // click 'new order' button on confirmation page
  const newOrderButton = await screen.findByRole("button", { name: /new order/i });
  await userEvent.click(newOrderButton);

  // check that scoops and toppings subtotals have been reset
  const scoopsSubTotal = await screen.findByText("Scoops total: $0.00");
  const toppingsSubTotal = await screen.findByText("Toppings total: $0.00");

  expect(scoopsSubTotal).toBeInTheDocument();
  expect(toppingsSubTotal).toBeInTheDocument();
});
