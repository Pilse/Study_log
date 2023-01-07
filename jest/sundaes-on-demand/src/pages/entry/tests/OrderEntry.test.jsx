import { render, screen, waitFor } from "../../../test-utils/testing-library-utils";
import userEvent from "@testing-library/user-event";
import OrderEntry from "../OrderEntry";
import { rest } from "msw";
import { server } from "../../../mocks/server";

test("handles error for scoops and topping routes", async () => {
  server.resetHandlers(
    rest.get("https://localhost:3030/scoops", (req, res, ctx) => res(ctx.status(500))),
    rest.get("https://localhost:3030/topping", (req, res, ctx) => res(ctx.status(500)))
  );

  render(<OrderEntry setOrderPhase={jest.fn()} />);

  await waitFor(async () => {
    const alerts = await screen.findAllByRole("alert");
    expect(alerts).toHaveLength(2);
  });
});

test("disable order button for no scoops ordered", async () => {
  render(<OrderEntry />);

  const orderButton = screen.getByRole("button", { name: /order/i });
  const scoopInput = screen.getByRole("spinbutton", { name: "Vanilla" });

  await userEvent.clear(scoopInput);

  expect(orderButton).toBeDisabled();

  await userEvent.type(scoopInput, "1");

  expect(orderButton).toBeEnabled();

  await userEvent.type(scoopInput, "0");

  expect(orderButton).toBeDisabled();
});
